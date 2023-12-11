#include <iostream>
using namespace std;

class Solution {
public:
    int Length_3n_plus_1(int n) {
        if(n==1){
            return 1;
        }

        if (n%2==0){
            return 1 + Length_3n_plus_1(n/2);
        }
        else {
            return 1 + Length_3n_plus_1(3*n+1);
        }
    }

    int my_pow(int value, int p=2){
        if(p==0)return 1;
        return value * my_pow(value, p-1);
    }

    int arr_max(int arr[], int len){
        if(len==1)return arr[0];

        int sub_array_mx = arr_max(arr, len-1);
        return max(sub_array_mx, arr[len-1]);
    }

    double arr_avg(int arr[], int len){
        if (len==1)return arr[0];

        double sub_arr_avg = arr_avg(arr, len-1);
        sub_arr_avg*=(len-1);
        return ((sub_arr_avg + arr[len-1])/len);
    }

    int arr_sum(int arr[], int len){
        if(len==1)return arr[0];

        int sub_arr_sum = arr_sum(arr, len-1);
        return (sub_arr_sum+arr[len-1]);
    }

    void arr_increment(int arr[], int len){
        if(len==0)return;

        arr_increment(arr, len-1);
        arr[len-1]+=len-1;
    }

    void arr_accumulate(int arr[], int len){
        if(len==0)return;

        int sum = 0;
        for(int i=0;i<len-1;i++){
            sum += arr[i];
        }
        arr[len-1] += sum;
        arr_accumulate(arr, len-1);
        //arr[len-1] += arr[len-2]; 5head
    }

    void left_mx(int arr[], int len){
        if(len==0)return;

        int mx = max(arr[0], arr[len-2]);
        if (arr[len-1] < mx){
            arr[len-1] = mx;
        }
        left_mx(arr, len-1);
        //arr[len-1]=max(arr[len-1], arr[len-2]); 5head
    }

    void right_mx(int arr[], int len, int start_position=0){
        if(start_position==len-1)return;

        right_mx(arr, len, start_position+1);
        arr[start_position]=max(arr[start_position], arr[start_position+1]);
    }

    int suffix_sum(int arr[], int len, int target){
        if (target==0)return 0;

        return arr[len-1] + suffix_sum(arr, len-1, target-1);
    }

    bool isPalindrome(int arr[], int len, int starting_position=-1){
        if(starting_position==len)return true;

        if(arr[starting_position+1]!=arr[len-1]){
            return false;
        }
        return isPalindrome(arr, len-1, starting_position+1);
    }

    bool isPrefix(string s, string prefix, int start_position=0){
        if(start_position>(int)prefix.size()-1)return true;

        if(s[start_position] != prefix[start_position]){
            return false;
        }
        return isPrefix(s, prefix, start_position+1);
    }

    bool isPrime(int n, int counter=3){
        //All those are base cases so if the compiler did'nt enter one of those we are gucci.
        if(n==2)return true;
        if(n==counter)return true;
        if(n<=1 || n%2==0)return false;
        if(n%counter==0)return false;

        return isPrime(n, counter+1);
    }

    int count_primes(int start, int End){
        if (start > End)return 0;

        int result = count_primes(start+1, End);
        if(isPrime(start)){
            result++;
        }
        return result;
    }


    int path_sum(int grid[100][100], int row, int col, int ROWS, int COLS){

    }

    bool legal_move(int r, int c, int Rows, int Cols){
        if (Cols-c==1){
            return false;
        }
        if (Rows-r==1){
            return false;
        }
    }

};



int main()
{
    //Solution solution;
    //cout << solution.Length_3n_plus_1(6);
    //cout << solution.my_pow(7, 3);
    //int arr[] = {1,8,2,10,3};
    //int arr2[] = {1,2,3,2,1};
    /**************Grid Sum****************/
    int r, c, Rows=0, Cols=0;
    cin>>r>>c;
    int arr3[r][c] = {0};
    //first we populate the array
    for (int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> arr3[i][j];
        }
    }
    int sum=arr3[Rows][Cols];
    while(Rows<r && Cols<c){

        int right = arr3[Rows][Cols+1];
        int bottom = arr3[Rows+1][Cols];
        int dig = arr3[Rows+1][Cols+1];

        int biggest = max(right, max(bottom, dig));
        if (biggest == right){
            Cols++;
            sum+=biggest;
        }
        if (biggest == bottom){
            Rows++;
            sum+=biggest;
        }
        if (biggest == dig){
            Rows++;
            Cols++;
            sum+=biggest;
        }
    }
    cout << "Sum is " << sum << endl;
    //3 3 1 7 8 2 10 11 20 5 9
    /*************************************/
    //cout << solution.arr_max(arr, 5);
    //cout << solution.arr_avg(arr, 5);
    //cout << solution.arr_sum(arr, 5);
    //solution.arr_increment(arr, 5);
    //solution.arr_accumulate(arr, 5);
    //solution.left_mx(arr, 5);
    //solution.right_mx(arr, 5, 0);
    //cout << solution.suffix_sum(arr, 5, 3);
    //cout << solution.isPalindrome(arr2, 5);
    //cout << solution.isPrefix("abcdefgh", "abd");
    //cout << solution.count_primes(10, 20);
    /*for(int i=0;i<5;i++){
        cout << arr[i] << " ";
    }*/
    return 0;
}
