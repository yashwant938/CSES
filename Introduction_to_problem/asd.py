import streamlit as st
from datetime import datetime
import math

def main():
    st.set_page_config(page_title="Review Tracker", layout="wide", page_icon="📌")
    
    # Enhanced Custom CSS
    st.markdown("""
    <style>
    :root {
        --done-color: #2ecc71;
        --not-done-color: #e74c3c;
        --review-color: #9b59b6;
    }
    body {
        background-color: #f4f6f9;
        font-family: 'Inter', sans-serif;
    }
    .header {
        font-size: 42px !important;
        font-weight: 900 !important;
        color: #2c3e50 !important;
        text-align: center;
        margin-bottom: 20px;
        text-shadow: 2px 2px 4px rgba(0,0,0,0.1);
    }
    .quote {
        font-size: 20px !important;
        font-style: italic !important;
        color: #7f8c8d !important;
        text-align: center;
        margin-bottom: 30px;
        padding: 15px;
        background-color: #ecf0f1;
        border-radius: 10px;
        box-shadow: 0 4px 6px rgba(0,0,0,0.05);
    }
    .user-cards {
        display: flex;
        gap: 20px;
        margin-bottom: 30px;
    }
    .user-card {
        flex: 1;
        background-color: white;
        border-radius: 15px;
        padding: 20px;
        box-shadow: 0 4px 12px rgba(0,0,0,0.1);
    }
    .user-content {
        margin-top: 30px;
    }
    .progress-circle {
        width: 100px;
        height: 100px;
        border-radius: 50%;
        display: flex;
        align-items: center;
        justify-content: center;
        margin: 0 auto 15px;
        font-size: 20px;
        font-weight: bold;
        box-shadow: 0 4px 12px rgba(0,0,0,0.1);
        position: relative;
        background: conic-gradient(
            var(--done-color) 0% calc(var(--done-percent) * 1%),
            var(--review-color) calc(var(--done-percent) * 1%) calc((var(--done-percent) + var(--review-percent)) * 1%),
            var(--not-done-color) calc((var(--done-percent) + var(--review-percent)) * 1%) 100%
        );
    }
    .progress-inner {
        width: 80px;
        height: 80px;
        background: white;
        border-radius: 50%;
        display: flex;
        align-items: center;
        justify-content: center;
    }
    .progress-label {
        font-size: 14px;
        text-align: center;
        margin-bottom: 15px;
        color: #2c3e50;
    }
    .question-grid {
        display: grid;
        grid-template-columns: repeat(auto-fill, minmax(300px, 1fr));
        gap: 15px;
        margin-top: 20px;
    }
    .question-card {
        background-color: white;
        border-radius: 10px;
        padding: 15px;
        box-shadow: 0 2px 8px rgba(0,0,0,0.1);
    }
    .question-text {
        font-size: 14px;
        margin-bottom: 10px;
        color: #2c3e50;
    }
    .status-buttons {
        display: flex;
        gap: 5px;
        margin-top: 5px;
    }
    .status-btn {
        flex: 1;
        padding: 3px 5px;
        border-radius: 4px;
        font-size: 11px;
        text-align: center;
        cursor: pointer;
        border: none;
        transition: all 0.2s;
    }
    .status-btn:hover {
        opacity: 0.9;
    }
    .done-btn {
        background-color: var(--done-color);
        color: white;
    }
    .not-done-btn {
        background-color: var(--not-done-color);
        color: white;
    }
    .review-btn {
        background-color: var(--review-color);
        color: white;
    }
    .active-status {
        box-shadow: 0 0 0 2px white, 0 0 0 4px currentColor;
    }
    .question-meta {
        font-size: 11px;
        color: #7f8c8d;
        margin-top: 5px;
    }
    .add-question-form {
        background-color: white;
        border-radius: 10px;
        padding: 15px;
        box-shadow: 0 2px 8px rgba(0,0,0,0.1);
        margin-bottom: 20px;
    }
    .stats-container {
        display: flex;
        justify-content: space-around;
        margin-bottom: 15px;
        text-align: center;
    }
    .stat-item {
        padding: 5px 10px;
        border-radius: 5px;
        font-size: 12px;
        font-weight: bold;
    }
    .stat-done {
        background-color: var(--done-color);
        color: white;
    }
    .stat-review {
        background-color: var(--review-color);
        color: white;
    }
    .stat-not-done {
        background-color: var(--not-done-color);
        color: white;
    }
    .user-header {
        text-align: center;
        margin-bottom: 15px;
        color: #2c3e50;
    }
    </style>
    """, unsafe_allow_html=True)
    
    # App header and quote
    st.markdown('<div class="header">📌 Review Tracker</div>', unsafe_allow_html=True)
    st.markdown('<div class="quote">"Track your 1000 questions journey - one question at a time"</div>', unsafe_allow_html=True)
    
    # Initialize session state
    if "questions_yash" not in st.session_state:
        st.session_state.questions_yash = []
    if "questions_ashwani" not in st.session_state:
        st.session_state.questions_ashwani = []
    
    # Status options
    STATUS_OPTIONS = ['Done', 'Not Done', 'Review']
    
    # User card component
    def user_card(user_name, questions_key):
        # Calculate stats
        total = len(st.session_state[questions_key])
        done = sum(1 for q in st.session_state[questions_key] if q.get("status") == "Done")
        review = sum(1 for q in st.session_state[questions_key] if q.get("status") == "Review")
        not_done = total - done - review
        
        done_percent = (done / total * 100) if total > 0 else 0
        review_percent = (review / total * 100) if total > 0 else 0
        not_done_percent = (not_done / total * 100) if total > 0 else 0
        
        # Calculate progress towards 1000 questions
        total_progress = min(total, 1000)
        
        st.markdown(f'''
        <div class="user-card">
            <h3 class="user-header">{user_name}</h3>
            <div class="progress-circle" 
                 style="--done-percent: {done_percent}; 
                        --review-percent: {review_percent}; 
                        --not-done-percent: {not_done_percent}">
                <div class="progress-inner">
                    {total}/1000
                </div>
            </div>
            <div class="stats-container">
                <div class="stat-item stat-done">Done: {done}</div>
                <div class="stat-item stat-review">Review: {review}</div>
                <div class="stat-item stat-not-done">Not Done: {not_done}</div>
            </div>
        </div>
        ''', unsafe_allow_html=True)
    
    # User content component
    def user_content(user_name, questions_key):
        with st.container():
            st.markdown(f'<div class="user-content">', unsafe_allow_html=True)
            
            # Add question form
            st.markdown('<div class="add-question-form">', unsafe_allow_html=True)
            with st.form(f"add_question_{user_name}", clear_on_submit=True):
                new_question = st.text_area(f"Add new question for {user_name}:", 
                                         height=60, 
                                         key=f"new_q_{user_name}",
                                         placeholder="Type your question here...")
                submitted = st.form_submit_button(f"➕ Add Question")
                if submitted and new_question.strip():
                    st.session_state[questions_key].append({
                        "text": new_question.strip(),
                        "status": "Not Done",
                        "last_reviewed": None,
                        "created_at": datetime.now().strftime("%Y-%m-%d %H:%M")
                    })
                    st.rerun()
            st.markdown('</div>', unsafe_allow_html=True)
            
            # Questions grid
            st.markdown('<div class="question-grid">', unsafe_allow_html=True)
            
            if not st.session_state[questions_key]:
                st.info(f"No questions added yet for {user_name}. Add your first question above!")
            else:
                for i, question in enumerate(st.session_state[questions_key]):
                    st.markdown(f'<div class="question-card">', unsafe_allow_html=True)
                    st.markdown(f'<div class="question-text">{question["text"]}</div>', unsafe_allow_html=True)
                    
                    # Status buttons
                    st.markdown('<div class="status-buttons">', unsafe_allow_html=True)
                    for status in STATUS_OPTIONS:
                        active = "active-status" if question.get("status") == status else ""
                        if st.button(status, 
                                   key=f"{user_name}_{i}_{status}",
                                   help=f"Mark as {status}"):
                            st.session_state[questions_key][i]["status"] = status
                            st.session_state[questions_key][i]["last_reviewed"] = datetime.now().strftime("%Y-%m-%d %H:%M")
                            st.rerun()
                        st.markdown(
                            f'<button class="status-btn {status.lower().replace(" ", "-")}-btn {active}" '
                            f'onclick="document.getElementById(\'{user_name}_{i}_{status}\').click()">{status}</button>',
                            unsafe_allow_html=True
                        )
                    st.markdown('</div>', unsafe_allow_html=True)
                    
                    # Metadata
                    st.markdown(f'''
                    <div class="question-meta">
                        Added: {question.get('created_at', 'N/A')} | 
                        Last reviewed: {question.get('last_reviewed', 'Never')}
                    </div>
                    ''', unsafe_allow_html=True)
                    
                    st.markdown('</div>', unsafe_allow_html=True)
            
            st.markdown('</div>', unsafe_allow_html=True)  # Close question-grid
            st.markdown('</div>', unsafe_allow_html=True)  # Close user-content
    
    # User cards at the top
    st.markdown('<div class="user-cards">', unsafe_allow_html=True)
    user_card("Ashwani", "questions_ashwani")
    user_card("Yash", "questions_yash")
    st.markdown('</div>', unsafe_allow_html=True)
    
    # User content sections below
    col1, col2 = st.columns(2)
    with col1:
        user_content("Ashwani", "questions_ashwani")
    with col2:
        user_content("Yash", "questions_yash")

if __name__ == "__main__":
    main()