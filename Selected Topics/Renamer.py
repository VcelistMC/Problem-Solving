import os
basePath = 'Sheet 1/'

problems = {
    'A': 'Absolute Differences',
    'B': 'Rectangles',
    'C': 'Smallest',
    'D': 'Quality Over Price',
    'E': 'Palindrome Wannabe',
    'F': 'Gap Sums',
    'G': 'Fixing Matrices',
    'H': 'Card Out, Card Down',
    'I': 'Dictionary Making',
    'J': 'Pricey Words',
    'K': 'Names Enumeration',
    'L': 'It Takes Two',
    'M': 'One of a Letter',
    'N': 'Shifted Keyboard',
    'O': 'Clear \'em All',
    'P': 'Counting Wood',
    'Q': 'Name Changer',
    'R': 'Sum of Two, Power of Two',
    'S': 'Rebuild The Heap',
    'T': 'Minimum Disappointments',
    'U': 'Addition Costs'
}
for file in os.listdir(basePath):
    problemName = problems[file[0]]
    newName = file
    newName = newName.replace(file[0], problemName)
    os.rename(basePath + file,basePath + newName)