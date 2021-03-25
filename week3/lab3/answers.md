What do we know?

    Selection Sort:         O = n^2
                        Omega = n^2
    - sorted and random should be equal (and slow)

    Bubble Sort:            O = n^2
                        Omega = n-1
    - sorted should be faster

    Merge Sort:         Theta = n log n 
    - sorted and random should be equal (and fast)
                       
sort1 uses: Bubble Sort

     rand5000:  .074
    rand10000:  .291
    rand50000: 8.153 
    
      rev5000:  .096  
     rev10000:  .369 
     rev50000: 8.431
    
     sort5000:  .015 
    sort10000:  .029
    sort50000:  .144 

How do you know?: 
    Large discrepencies b/w slow and fast sorts.


sort2 uses: Merge Sort

     rand5000:  .013
    rand10000:  .034
    rand50000:  .162 
    
      rev5000:  .016 
     rev10000:  .029 
     rev50000:  .169 
    
     sort5000:  .015 
    sort10000:  .029 
    sort50000:  .151 
    
How do you know?:
    Fastest of all 3,
    practically equal sort times across datasets.

sort3 uses: Selection Sort

     rand5000:  .033 
    rand10000:  .096 
    rand50000: 1.762 
    
      rev5000:  .032 
     rev10000:  .134 
     rev50000: 1.803 
    
     sort5000:  .032 
    sort10000:  .094 
    sort50000: 2.105 
    
How do you know?:
    Similar sort times across datasets,
    but is much slower than sort2.
