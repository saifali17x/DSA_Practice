class Solution {
public:

    // ==========================
    // ENCODE FUNCTION
    // ==========================
    string encode(vector<string>& strs) {
        string res;

        // Loop through each string in the array
        for(const string &s : strs) {
            // For each string, append its length + '#' + actual string
            // Example: "leet" -> "4#leet"
            // This handles single or multiple digit lengths automatically
            // The '#' acts as a separator so decode can find the length easily
            res += to_string(s.size()) + "#" + s;
        }

        // Return the single concatenated string representing the entire array
        // Example: ["leet","code"] -> "4#leet4#code"
        return res;
    }

    // ==========================
    // DECODE FUNCTION
    // ==========================
    vector<string> decode(string s) {
        vector<string> res; // Result vector to store decoded strings
        int i = 0;           // 'i' is our main cursor: points to start of current number/length

        // Loop until 'i' reaches the end of the string
        while(i < s.size()) {

            // --------------------------
            // Step 1: Find the '#'
            // --------------------------
            int j = i;                 // 'j' is a helper pointer; starts at 'i'
            while(s[j] != '#') {       // Move j forward until we find '#' which separates length from string
                j++;
            }
            // Now, 'i' points at the first digit of the number
            // 'j' points at '#' right after the number

            // --------------------------
            // Step 2: Extract the length
            // --------------------------
            // s.substr(i, j-i) -> takes substring starting at i, length = (j-i)
            // It means: start at index i, take (j - i) characters.
            // Example: if s = "12#hello", i=0, j=2 -> s.substr(0,2) = "12"
            // stoi(...) converts this substring to integer: length of next string
            int length = stoi(s.substr(i, j - i));

            // --------------------------
            // Step 3: Move i to start of actual string
            // --------------------------
            // 'i = j + 1' moves i past the '#' so it now points at first character of the actual string
            i = j + 1;

            // --------------------------
            // Step 4: Calculate end position for current string
            // --------------------------
            // 'j = i + length' makes j point just past the end of the current string i.e at the next number
            j = i + length;

            // --------------------------
            // Step 5: Extract the string and store
            // --------------------------
            // s.substr(i, length) -> extract 'length' characters starting from i
            // This works even if the string contains '#' or spaces, because we use the length
            res.push_back(s.substr(i, length));

            // --------------------------
            // Step 6: Move i to start of next block
            // --------------------------
            // Set i = j to prepare for next iteration of the while loop
            // Now i points at the next number (length of next string)
            i = j;
        }

        // Return the reconstructed array of strings
        return res;
    }
};
