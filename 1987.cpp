#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    vector<pair<pair<int, int>, int>> segments;
    vector<int>points;
    vector<pair<pair<int, int>, int>> stek;
    vector<int>answer;
    int n, m, lef, righ, dot;
    cin >> n;
    for (int i = 0; i < n; i++ ) {
        cin >> lef;
        cin >> righ;
        segments.push_back(make_pair(make_pair(lef, righ), i+1));
    }
    segments.push_back(make_pair(make_pair(1000000001, 1000000001), n));
    cin >> m;
    for (int i = 0; i < m; i++ ) {
        cin >> dot;
        points.push_back(dot);
    }
    int c =0;
    int i=0;
    while(i < m) {
        if(stek.size()!=0){
            if((stek.back().first.first<=points[i])&&(points[i]<=stek.back().first.second)){
                if((segments[c].first.first<=points[i])&&(points[i]<=segments[c].first.second)){
                    stek.push_back(segments[c]);
                    c++;
                }
                else if (points[i]<segments[c].first.first) {
                    answer.push_back(stek.back().second);
                    i++;
                }
                else c++;
            }
            else stek.pop_back();
        }
        else{
            if(points[i]<segments[c].first.first)  {
                answer.push_back(-1);
                i++;
            }
            else if((segments[c].first.first<=points[i])&&(points[i]<=segments[c].first.second)){
                stek.push_back(segments[c]);
                c++;
            }
            else {
                c++;
            }
        }

    }
    for(i=0; i < answer.size(); i++){
        cout << answer[i]<< '\n';
    }
    return 0;
}
