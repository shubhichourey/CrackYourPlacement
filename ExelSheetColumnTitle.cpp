/*Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.*/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while(columnNumber>0){
            char c = 'A' + (columnNumber-1)%26;
            result = c + result;
            columnNumber = (columnNumber-1)/26;
        }
        return result;
    }
};