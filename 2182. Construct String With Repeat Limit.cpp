class Solution {
public:
    static string repeatLimitedString(string& s, int k) {
        int freq[26]={0}, hz=0;

        // Count frequency
        for (char c : s) 
            freq[c-'a']++;
        
        // Use C-array to act as max heap
        char heap[26];
        for (int i = 0; i < 26; i++) {
            if (freq[i]> 0) 
                heap[hz++]='a'+ i;
        }
        make_heap(heap, heap+hz);

        string ans;
        ans.reserve(s.size());

        while (hz > 0) {
            pop_heap(heap, heap + hz);
            char c= heap[hz-1];
            hz--;

            int& f=freq[c-'a'];
            int use=min(f, k); // Add as many characters as possible (up to k)
            ans.append(use, c);
            f-= use;

            if (f > 0 && hz > 0) {
                // Use the next character to interleave
                pop_heap(heap, heap+hz);
                char c2=heap[hz-1];
                hz--;

                ans.push_back(c2);
                int& f2 = freq[c2 - 'a'];
                f2--;

                // Reinsert both characters back 
                if (f2 > 0) {
                    heap[hz++]=c2;
                    push_heap(heap, heap + hz);
                }
                heap[hz++] = c;
                push_heap(heap, heap + hz);
            } 
        }

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

