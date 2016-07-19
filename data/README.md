To change the keyword you must first create a new corpus. Feel free to just use the current corpus and append whatever word you'd like to be detected.
 Once you have created this corpus, you can create the other files at:  
http://www.speech.cs.cmu.edu/tools/lmtool-new.html  
  
If you do not use the same names for the files, then you will have to update the launch file of the program at ```exercise_interface/launch/interface.launch```  
  
Finally, you will need to update a variable in the file ```exercise_interface/src/state_detector.cpp``` which looks for the special keyword in the sphinx output. 
