class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long sum = skill[0] * skill[skill.size()-1], req = skill[0] + skill[skill.size()-1];
        for(int i=1 ,j=skill.size()-2 ; i<j ; i++,j--){
            if(skill[i]+skill[j]!=req)return -1;
            sum += (skill[i]*skill[j]);
        }
        return sum;
    }
};
