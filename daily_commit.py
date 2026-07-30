import subprocess
import sys
import time  # Imported for time.sleep()


def run_command(command, capture_output=False):
    """Run a shell command and return the result."""
    try:
        if capture_output:
            result = subprocess.run(
                command,
                shell=True,
                check=False,
                text=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
            )
            return result.returncode, result.stdout.strip()
        else:
            result = subprocess.run(command, shell=True, check=False)
            return result.returncode, None
    except Exception as e:
        print(f"\033[91m[!] Error executing command: {e}\033[0m")
        return 1, None


def main():
    print("\033[96m[*] Staging changes...\033[0m")
    run_command("git add .")
    time.sleep(5)  # Sleep station 1

    # Check if there are changes to commit
    code, _ = run_command("git diff --cached --quiet")
    if code == 0:
        print(
            "\033[92m[+] Working tree is clean. Nothing new to commit.\033[0m"
        )
        sys.exit(0)

    print("\033[96m[*] Generating commit message from Python...\033[0m")
    time.sleep(5)  # Sleep station 2
    code, commit_message = run_command(
        f"{sys.executable} git_commit.py", capture_output=True
    )

    if code != 0 or not commit_message:
        print("\033[91m[!] Failed to generate commit message.\033[0m")
        sys.exit(1)

    print("\033[96m[*] Committing changes...\033[0m")
    time.sleep(5)  # Sleep station 3
    try:
        git_commit = subprocess.Popen(
            ["git", "commit", "-F", "-"],
            stdin=subprocess.PIPE,
            text=True,
        )
        git_commit.communicate(input=commit_message)
        commit_code = git_commit.returncode
    except Exception as e:
        print(f"\033[91m[!] Failed to commit: {e}\033[0m")
        sys.exit(1)

    if commit_code != 0:
        print("\033[91m[!] Commit failed.\033[0m")
        sys.exit(1)

    print("\033[96m[*] Pushing to remote repository...\033[0m")
    time.sleep(5)  # Sleep station 4
    push_code, _ = run_command("git push")

    if push_code == 0:
        print(
            "\033[92m[?] Successfully pushed todays progress to GitHub!\033[0m"
        )
    else:
        print("\033[91m[!] Push failed.\033[0m")
        sys.exit(1)


if __name__ == "__main__":
    main()