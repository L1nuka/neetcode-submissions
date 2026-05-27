class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> lib = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0'};
        int ptrA = 0;
        int ptrB = s.size()-1;
        while(ptrA < ptrB){
            char A = tolower(s[ptrA]);
            char B = tolower(s[ptrB]);
            if (find(lib.begin(),lib.end(),A) == lib.end()){
                ptrA++;
                continue;
            }
            if (find(lib.begin(),lib.end(),B) == lib.end()){
                ptrB--;
                continue;
            }
            if (A!=B)
                return false;
            ptrA++;
            ptrB--;
        }
        return true;
    }
};
