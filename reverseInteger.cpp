int reverse(int x) {
    int temp = abs(x);
    long result = 0;
    while(temp > 0){
        result *= 10;
        result += temp%10;
        temp /= 10;
    }
    if(result > INT_MAX || result < INT_MIN){
        return 0;
    }
    if(x < 0){
        result*= -1;
    }
    return result;    //can use a long even for return type int
};

int main(){
    int input = 123;
    cout<<reverse(input);
}