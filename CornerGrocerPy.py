# Carolyn M. Rios Borges
# Sunday August 4, 2024
# CS-210: Module 7 Assignment: Project Three
# Prof. Brian Morgan

# A simpler, Python version of Corner Grocer.
# It has the same primary purposes as the C++ version: 
# Read "CS210_ProjectThree_InputFile.txt", determine frequency in which a word appears,
# and save frequency information in new file called "frequency.dat".

# Open "CS210_ProjectThree_InputFile.txt".
# CornerGrocer = open("CS210_ProjectThree_InputFile.txt")

def freqTracker():

    items = None

    with open("CS210_ProjectThree_InputFile.txt") as userItems:
        items = userItems.readlines()

    return items

# Read "CS210_ProjectThree_InputFile.txt".
def getUserItem():

    userItems = {}
    item = freqTracker()

    # Loop through each item of the text file.

    for itemFreq in item:
        itemFreq = itemFreq.strip()

        if itemFreq in userItems:
            userItems[itemFreq] += 1

        else:
            userItems[itemFreq] = 1
        
    return userItems
    
# Get item's frequency and save frequency in new file called "frequency.dat".  
def findFreq():
    userItems = getUserItem()

    # Output item frequency.
    for item, itemFreq in userItems.items():
        print(item, " ", itemFreq)

# Return one item.
def saveFreq(item):
    userItems = getUserItem

    return userItems[item]

# Create "frequency.dat" file.
def outputFreq():
    userItems = getUserItem()

    newCornerGrocer = open("frequency.dat", 'w')
    newCornerGrocer.truncate()

    for item, itemFreq in userItems.items():
        newCornerGrocer.write(item + " " + str(itemFreq) + "\n")    

    newCornerGrocer.flush()
    newCornerGrocer.close()

# Define entry point.
if __name__ == "__main__":
    outputFreq()



