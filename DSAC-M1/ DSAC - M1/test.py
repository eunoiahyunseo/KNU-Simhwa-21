import numpy as np
import pandas as pd

# with open("./data/radishsurvey.txt") as file:
#     for line in file:
#         line = line.strip()
#         parts = line.split(" - ")
#         name = parts[0]
#         vote = parts[1]
#         print(name + " voted for " + vote)


#===============================================

# print("Counting votes for White Icicle...")
# count = 0

# with open("./data/radishsurvey.txt") as file:
#     for line in file:
#         line = line.strip()
#         parts = line.split(" - ")
#         name, vote = parts
#         if vote == "White Icicle":
#             print(name + " likes White Icicle!")
#             count += 1
# print(count)


#===============================================


# counts = dict()

# with open("./data/radishsurvey.txt") as file:
#     for line in file:
#         line = line.strip()
#         name, vote = line.split(" - ")
#         if vote not in counts:
#             counts[vote] = 1
#         else:
#             counts[vote] += 1
            
# sorted_counts = sorted(counts.items(), key=lambda x:x[1], reverse=True)
# for value, counts in sorted_counts:
#     print(value, ": ", counts)



# ===============================================


# counts = dict()

# with open("./data/radishsurvey.txt") as file:
#     for line in file:
#         line = line.strip()
#         name, vote = line.split(" - ")
        
#         vote = vote.strip().capitalize().replace("  ", " ")
#         if not vote in counts:
#             counts[vote] = 1
#         else:
#             counts[vote] = counts[vote] + 1
            
# print(counts)
    
    
# ===============================================


# counts = {}
# voted = []
# winner_votes = 0
# winner_name = "No winner"


# def clean_string(s):
#     return s.strip().capitalize().replace("  ", " ")


# def has_already_voted(name):
#     if name in voted:
#         print(name + " has already voted! Fraud")
#         return True
#     return False


# def count_vote(radish):
#     if not radish in counts:
#         counts[radish] = 1
#     else:
#         counts[radish] += 1
        
# with open("./data/radishsurvey.txt") as file:
#     for line in file:
#         line = line.strip()
#         name, vote = line.split(" - ")
        
#         name = clean_string(name)
#         vote = clean_string(vote)
        
#         if not has_already_voted(name):
#             count_vote(vote)
#             voted.append(name)
            
# # print("Results: ")
# # print()
# # for name in counts:
# #     print(name + ": " + str(counts[name]))

# for name in counts:
#     if counts[name] > winner_votes:
#         winner_name = name

# print("The winner is: " + winner_name)


# #===============================================

# import numpy as np
# import matplotlib.pyplot as plt
# names = []
# votes = []
# for radish in counts:
#     names.append(radish)
#     votes.append(counts[radish])

# x = np.arange(len(counts))

# plt.bar(x, votes)
# plt.xticks(x + 0.5, names, rotation=90)
# plt.show()


# #===============================================




