import os
from datetime import datetime, timezone, timedelta
import requests
from dotenv import load_dotenv

load_dotenv()

LEETCODE_GRAPHQL_URL = "https://leetcode.com/graphql"
USERNAME = os.getenv("LEETCODE_USERNAME")

QUERY_RECENT_AC = """
query recentAcSubmissions($username: String!, $limit: Int!) {
  recentAcSubmissionList(username: $username, limit: $limit) {
    id
    title
    titleSlug
    timestamp
  }
}
"""

def fetch_past_accepted_submissions(days_ago=0, limit=50):
    """
    Fetches recent accepted submissions and filters those solved on a specific past day.
    Default is days_ago=1 (yesterday).
    """
    variables = {
        "username": USERNAME,
        "limit": limit
    }
    
    response = requests.post(
        LEETCODE_GRAPHQL_URL,
        json={
            "query": QUERY_RECENT_AC,
            "variables": variables
        }
    )
    
    if response.status_code != 200:
        raise Exception(f"GraphQL query failed with status code {response.status_code}")
    
    data = response.json()
    submissions = data.get("data", {}).get("recentAcSubmissionList", [])
    
    if not submissions:
        return []

    # Calculate target date (e.g., yesterday)
    target_date = (datetime.now(timezone.utc) - timedelta(days=days_ago)).date()
    target_submissions = []
    seen_slugs = set()
    
    for sub in submissions:
        sub_date = datetime.fromtimestamp(int(sub["timestamp"]), tz=timezone.utc).date()
        
        if sub_date == target_date and sub["titleSlug"] not in seen_slugs:
            seen_slugs.add(sub["titleSlug"])
            target_submissions.append({
                "submission_id": sub["id"],
                "title": sub["title"],
                "title_slug": sub["titleSlug"],
                "timestamp": int(sub["timestamp"])
            })
            
    return target_submissions

if __name__ == "__main__":
    print(f"Fetching problems solved yesterday by {USERNAME}...")
    solved_yesterday = fetch_past_accepted_submissions(days_ago=0)
    print(f"Found {len(solved_yesterday)} unique problems from yesterday:")
    for prob in solved_yesterday:
        print(f" - {prob['title']} ({prob['submission_id']})")