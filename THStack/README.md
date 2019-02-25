THStack
====

How histograms with negative events are handled.

    root test.cxx
    
Result:

    negative bins are NOT plotted (or better, they are plotted but they are invisible). They do not contribute to the total. It is as if they were 0-events