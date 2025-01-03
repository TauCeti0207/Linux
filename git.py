'''
Descripttion: 
Author: tauceti0207
version: 
Date: 2024-08-25 00:12:59
LastEditors: tauceti0207
LastEditTime: 2024-09-08 22:40:18
'''
import subprocess
from datetime import datetime

def git_add_commit_push():
    try:
        # 执行 git add
        subprocess.run(['git', 'add', '.'], check=True)

        # 执行 git commit
        today = datetime.today().strftime('%Y-%m-%d')
        commit_message = f"Auto commit for {today}"
        subprocess.run(['git', 'commit', '-m', commit_message], check=True)

        # 执行 git push
        subprocess.run(['git', 'push'], check=True)

        print("Git add, commit, and push successful!")
    except subprocess.CalledProcessError as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    git_add_commit_push()