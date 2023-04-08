import sys, os
sys.stdin = open("../input.txt", "r")
sys.stdout = open("../output.txt", "w")
for line in sys.stdin:
    stripped = line.strip()
    if not stripped: break
    sys.stdout.write(line)