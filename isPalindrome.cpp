bool isPalindrome(int x) {
    if(x < 0){ return false; }
    long position = 1;
    long reverse = 0;
    while(position <= x){
        //121%10 = 1/1 = 1
        //121%100 = 21/10 = 2
        //121%1000 = 121/100 = 1
        reverse *=10;
        reverse += (x%(position * 10)) / position;
        position *= 10;
    }
    if(x == reverse){return true;}
    return false;
}
