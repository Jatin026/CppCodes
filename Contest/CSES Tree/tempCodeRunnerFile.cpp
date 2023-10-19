
    // cin>>t;
    auto start = chrono::high_resolution_clock::now();
 
    // Call the function, here sort()
    while(t--){
        solve();
    }
 
    // Get ending timepoint
    auto stop = chrono::high_resolution_clock::now();
 
    // Get duration. Substart timepoints to 
    // get duration. To cast it to proper unit
    // use duration cast method
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
 