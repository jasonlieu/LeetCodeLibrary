string addBinary(string a, string b) {
    int carry = 0;
    int index = 0;
    string result = "";
    while(index < a.length() || index < b.length()){
        int aPosition = 0;
        int bPosition = 0;
        if(index < a.length()){
            if(a[a.length() - index - 1] == '1'){
                aPosition = 1;
            }
        }
        if(index <b.length()){
            if(b[b.length() - index - 1] == '1'){
                bPosition = 1;
            }
        }
        if(aPosition + bPosition + carry >=2){        //carry
            if(aPosition + bPosition + carry == 3){
                result = "1" + result;
                carry = 1;
            }
            else if(aPosition + bPosition + carry == 2){
                result = "0" + result;
                carry = 1;
            }
        }
        else{ //0+0+0, 1+0+0, 0+0+1
            if(aPosition + bPosition + carry == 0){
                result = "0" + result;
                carry = 0;
            }
            else {
                result = "1" + result;
                carry = 0;
            }
        }
        index++;
    }
    if(carry == 1){
        return "1" + result;
    }
    return result;
}