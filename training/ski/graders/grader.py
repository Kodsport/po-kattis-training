GROUP_SCORES = [19, 24, 37, 20]
GROUP_CASES = [[1, 0], [1, 0, 4, 2, 3], [1, 8, 9, 0, 5, 4, 2, 3, 7, 6], [10, 1, 19, 8, 23, 9, 17, 0, 5, 15, 22, 14, 11, 16, 4, 13, 2, 3, 7, 12, 20, 18, 21, 6]]
import sys

def is_int(arg):
    try:
        int(arg)
        return True
    except:
        return False


def main():
    if "ignore" in sys.argv:
        print "AC 0"
    elif "groups" in sys.argv:
        scores = []
        for line in sys.stdin.readlines():
            verdict, score = line.split()
            if verdict != "AC":
                scores.append(0)
            else:
                scores.append(score)
        score = 0
        for group in range(len(GROUP_SCORES)):
            group_score = GROUP_SCORES[group]
            for case in GROUP_CASES[group]:
                if scores[case] == 0:
                    group_score = 0
            score += group_score
        print "AC %s" % score
    else:
        for line in sys.stdin.readlines():
            print line

main()

