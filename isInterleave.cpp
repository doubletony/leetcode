class Solution {
public:
    int getCounter(string s, int startI)
    {
        char sc = s[startI];
        int counter = 0;
        for (int i = startI; i < s.length(); i++)
        {
            if ( sc == s[i])
            {
                counter++;
            }
            else
            {
                return counter;
            }
        }
        return counter;
    }

    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    

        if ( (s1.length() == 0) && (s2 == s3))
        {
            return true;
        }

        if ( (s1.length() == 0) && (s2 != s3))
        {
            return false;
        }

        if ( (s2.length() == 0) && (s1 == s3))
        {
            return true;
        }

        if ( (s2.length() == 0) && (s1 != s3))
        {
            return false;
        }


        int i,j, k;
        int lenS1, lenS2, lenS3;
        
        i = j = k = 0;
        lenS1 = s1.length();
        lenS2 = s2.length();
        lenS3 = s3.length();
        if ( (lenS1 + lenS2) != lenS3)
        {
            return false;
        }

        while( (i < lenS1) && (j < lenS2) )
        {
            if ( (s3[k] == s1[i]) && (s3[k] != s2[j]) )
            {
                i++;
                k++;
                continue;
            }

            if ( (s3[k] != s1[i]) && (s3[k] == s2[j]) )
            {
                j++;
                k++;
                continue;
            }

            if ( (s3[k] != s1[i]) && (s3[k] != s2[j]) )
            {
                return false;
            }

            if ( (s3[k] == s1[i]) && (s3[k] == s2[j]) )
            {
                // hmm, let's handle it
                int counteri, counterj, counterk;
                counteri = counterj = counterk = 0;
                counteri = getCounter(s1, i);
                counterj = getCounter(s2, j);
                counterk = getCounter(s3, k);

                if ( (counteri + counterj) < counterk )
                {
                    return false;
                }
                else if ((counteri + counterj) ==  counterk )
                {
                    i += counteri;
                    j += counterj;
                    k += counterk;
                }
                else
                {
                    // we can assume that k+counterk is impossible to be the last one in S3 
                    // why?  Because ...
                    if ( (i+counteri) < (lenS1) && (s1[i+counteri] == s3[k+counterk] ) )
                    {
                        string subs1, subs2, subs3;
                        subs1 = s1.substr(i+counteri);
                        subs2 = s2.substr(j);
                        subs3 = s3.substr(k+counteri);
                        if ( isInterleave(subs1, subs2, subs3) )
                        {
                            return true;
                        }
                    }
                    
                    if ( (j+counterj) < (lenS2) && (s2[j+counterj] == s3[k+counterk] ) )
                    {
                        string subs1, subs2, subs3;
                        subs1 = s1.substr(i);
                        subs2 = s2.substr(j+counterj);
                        subs3 = s3.substr(k+counterj);
                        if ( isInterleave(subs1, subs2, subs3) )
                        {
                            return true;
                        }
                    }
                    return false;
                }
            }
        }

        if ( (i == lenS1) && (j < lenS2))
        {
            string sus2 = s2.substr(j);
            string sus3 = s3.substr(k);
            if (sus2 != sus3)
            {
                return false;
            }
        }

        if ( (j == lenS2) && (i < lenS1))
        {
            string sus1 = s1.substr(i);
            string sus3 = s3.substr(k);
            if (sus1 != sus3)
            {
                return false;
            }
        }
        return true;
 
    }
};