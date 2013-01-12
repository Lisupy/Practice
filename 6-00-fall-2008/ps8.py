# 6.00 Problem Set 8
#
# Intelligent Course Advisor
#
# Name:
# Collaborators:
# Time:
#

import time

SUBJECT_FILENAME = "subjects.txt"
VALUE, WORK = 0, 1


#
# Problem 1: Building A Subject Dictionary
# Done.
def loadSubjects(filename):
    """
    Returns a dictionary mapping subject name to (value, work), where the name
    is a string and the value and work are integers. The subject information is
    read from the file named by the string filename. Each line of the file
    contains a string of the form "name,value,work".

    returns: dictionary mapping subject name to (value, work)
    """
    subjects = {}
    # The following sample code reads lines from the specified file and prints
    # each one.
    inputFile = open(filename)
    for line in inputFile:
        #print line
        name,value,work = line.split(",")
        work = work.strip("\n")
        subjects[name] = (int(value),int(work))
    
    return subjects
    # Done: Instead of printing each line, modify the above to parse the name,
    # value, and work of each subject and create a dictionary mapping the name
    # to the (value, work).

def getValWork(subjects):
    totalVal, totalWork = 0,0
    res = 'Course\tValue\tWork\n======\t====\t=====\n'
    subNames = subjects.keys()
    subNames.sort()
    for s in subNames:
       val = subjects[s][VALUE]
       work = subjects[s][WORK]
       res = res + s + '\t' + str(val) + '\t' + str(work) + '\n'
       totalVal += val
       totalWork += work
    res = res + '\nTotal Value:\t' + str(totalVal) +'\n'
    res = res + 'Total Work:\t' + str(totalWork) + '\n'
    return totalVal, totalWork
   
    
def printSubjects(subjects):
    """
    Prints a string containing name, value, and work of each subject in
    the dictionary of subjects and total value and work of all subjects
    """
    totalVal, totalWork = 0,0
    if len(subjects) == 0:
        return 'Empty SubjectList'
    res = 'Course\tValue\tWork\n======\t====\t=====\n'
    subNames = subjects.keys()
    subNames.sort()
    for s in subNames:
        val = subjects[s][VALUE]
        work = subjects[s][WORK]
        res = res + s + '\t' + str(val) + '\t' + str(work) + '\n'
        totalVal += val
        totalWork += work
    res = res + '\nTotal Value:\t' + str(totalVal) +'\n'
    res = res + 'Total Work:\t' + str(totalWork) + '\n'
    print res

def cmpValue(subInfo1, subInfo2):
    """
    Returns True if value in (value, work) tuple subInfo1 is GREATER than
    value in (value, work) tuple in subInfo2
    """
    val1 = subInfo1[VALUE]
    val2 = subInfo2[VALUE]
    return  val1 > val2

def cmpWork(subInfo1, subInfo2):
    """
    Returns True if work in (value, work) tuple subInfo1 is LESS than than work
    in (value, work) tuple in subInfo2
    """
    work1 = subInfo1[WORK]
    work2 = subInfo2[WORK]
    return  work1 < work2

def cmpRatio(subInfo1, subInfo2):
    """
    Returns True if value/work in (value, work) tuple subInfo1 is 
    GREATER than value/work in (value, work) tuple in subInfo2
    """
    val1 = subInfo1[VALUE]
    val2 = subInfo2[VALUE]
    work1 = subInfo1[WORK]
    work2 = subInfo2[WORK]
    return float(val1) / work1 > float(val2) / work2

#
# Problem 2: Subject Selection By Greedy Optimization
# Done.
def greedyAdvisor(subjects, maxWork, comparator):
    """
    Returns a dictionary mapping subject name to (value, work) which includes
    subjects selected by the algorithm, such that the total work of subjects in
    the dictionary is not greater than maxWork.  The subjects are chosen using
    a greedy algorithm.  The subjects dictionary should not be mutated.

    subjects: dictionary mapping subject name to (value, work)
    maxWork: int >= 0
    comparator: function taking two tuples and returning a bool
    returns: dictionary mapping subject name to (value, work)
    """
    selected = {}
    total_work = 0
    while True:
        find_flag = False;
        chosen_name = "";
     #   print len(subjects)
        for name in subjects:
            if find_flag == False or comparator(subjects[name], chosen):
                chosen = subjects[name];
                chosen_name = name;
                find_flag = True
        work = chosen[WORK];
        if total_work + work > maxWork:
            break;
        total_work = total_work + work
        selected[chosen_name] = chosen;
        subjects.pop(chosen_name)
    return selected;

def bruteForceAdvisor(subjects, maxWork):
    """
    Returns a dictionary mapping subject name to (value, work), which
    represents the globally optimal selection of subjects using a brute force
    algorithm.

    subjects: dictionary mapping subject name to (value, work)
    maxWork: int >= 0
    returns: dictionary mapping subject name to (value, work)
    """
    nameList = subjects.keys()
    tupleList = subjects.values()
    bestSubset, bestSubsetValue = \
            bruteForceAdvisorHelper(tupleList, maxWork, 0, None, None, [], 0, 0)
    outputSubjects = {}
    for i in bestSubset:
        outputSubjects[nameList[i]] = tupleList[i]
    return outputSubjects

def bruteForceAdvisorHelper(subjects, maxWork, i, bestSubset, bestSubsetValue,
                            subset, subsetValue, subsetWork):
    # Hit the end of the list.
    if i >= len(subjects):
        if bestSubset == None or subsetValue > bestSubsetValue:
            # Found a new best.
            return subset[:], subsetValue
        else:
            # Keep the current best.
            return bestSubset, bestSubsetValue
    else:
        s = subjects[i]
        # Try including subjects[i] in the current working subset.
        if subsetWork + s[WORK] <= maxWork:
            subset.append(i)
            bestSubset, bestSubsetValue = bruteForceAdvisorHelper(subjects,
                    maxWork, i+1, bestSubset, bestSubsetValue, subset,
                    subsetValue + s[VALUE], subsetWork + s[WORK])
            subset.pop()
        bestSubset, bestSubsetValue = bruteForceAdvisorHelper(subjects,
                maxWork, i+1, bestSubset, bestSubsetValue, subset,
                subsetValue, subsetWork)
        return bestSubset, bestSubsetValue

#
# Problem 3: Subject Selection By Brute Force
# Done.
def bruteForceTime():
    """
    Runs tests on bruteForceAdvisor and measures the time required to compute
    an answer.
    """
    subjects = loadSubjects(SUBJECT_FILENAME);
    for i in range(0, 100000):
        start_time = time.time();
        bruteForceAdvisor(subjects, i);
        end_time = time.time();
        print str(i) + ":" + str(end_time - start_time) + "s"
   

# Problem 3 Observations
# ======================
#
# Done: write here your observations regarding bruteForceTime's performance
# 0:0.000999927520752s
# 1:0.00300002098083s
# 2:0.010999917984s
# 3:0.0429999828339s
# 4:0.151000022888s
# 5:0.444000005722s
# 6:0.990000009537s
# 7:2.92900013924s
# 8:12.5279998779s
# 9:31.128000021s
# 10:90.4519999027s
# 11:216.582000017s


#
# Problem 4: Subject Selection By Dynamic Programming
#
def dpAdvisor(subjects, maxWork):
    """
    Returns a dictionary mapping subject name to (value, work) that contains a
    set of subjects that provides the maximum value without exceeding maxWork.

    subjects: dictionary mapping subject name to (value, work)
    maxWork: int >= 0
    returns: dictionary mapping subject name to (value, work)
    """
    dp = {0:({}, 0)} 
    maxValue,maxSubjects = 0, {}
    for name,(value, work) in subjects.iteritems():
        dp_old = dp.copy();
        for usedWork,(selected, sumValue)  in dp_old.iteritems():
            totalWork = work+usedWork;
            if totalWork > maxWork:
                continue;
            totalValue = sumValue + value;
            selectedSubjects = selected.copy();
            selectedSubjects[name] = (value, work)
            #k = dp.has_key[totalValue]
         #   k = dp[totalValue][1];
            if  dp.has_key(totalWork) == False or totalValue > dp[totalWork][1]:
                dp[totalWork] = (selectedSubjects, totalValue)
                if totalValue > maxValue:
                    maxValue, maxSubjects =  totalValue, selectedSubjects;
    return maxSubjects
    

#
# Problem 5: Performance Comparison
# Done.
def dpTime():
    """
    Runs tests on dpAdvisor and measures the time required to compute an
    answer.
    """
    subjects = loadSubjects(SUBJECT_FILENAME);
    for i in range(0, 30):
        start_time = time.time();
        a = dpAdvisor(subjects, i);
        end_time = time.time();
        dp_time = end_time - start_time;
        
        start_time = time.time();
        b = bruteForceAdvisor(subjects, i);
        end_time = time.time();
        bruteForceTime = end_time - start_time;
        assert  getValWork(a) == getValWork(b)
        print "#%2d: %3.5fs %3.5fs"%(i,dp_time,bruteForceTime)
              
       

# Problem 5 Observations
# ======================
#
# Done: write here your observations regarding dpAdvisor's performance and
# how its performance compares to that of bruteForceAdvisor.
# 0: 0.00100s 0.00100s
# 1: 0.00000s 0.00300s
# 2: 0.00000s 0.01100s
# 3: 0.00100s 0.04400s
# 4: 0.00100s 0.15300s
# 5: 0.00100s 0.49700s
# 6: 0.00100s 1.99100s
# 7: 0.00100s 6.18800s
# 8: 0.00500s 15.66500s
# 9: 0.00200s 27.63100s
#10: 0.00100s 62.44700s
#11: 0.00200s 196.56500s




##############Test Code#########
if __name__ == "__main__":
    print "Problem 1:";
    subjects = loadSubjects(SUBJECT_FILENAME);
    printSubjects(subjects);
    print "Problem 2:";
    selected = greedyAdvisor(subjects, 30, cmpRatio)
    printSubjects(selected);
    print "Problem 3:";
    #bruteForceTime()
    print "Problem 4:";
    dpTime();