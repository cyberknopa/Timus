#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int comp1 (pair<int, int>primo, pair<int, int>secondo){
    if(primo.first == secondo.first)
        return(primo.second < secondo.second);
    else
        return (primo.first < secondo.first);
}

int comp2 (pair<int, int>primo, pair<int, int>secondo){
    if(primo.second == secondo.second)
        return(primo.first<secondo.first);
    else
        return (primo.second<secondo.second);
}

int main(){

    int n, m, lef, righ;
    cin >> n;
    vector <pair<int, int>> segments;
    vector <pair<int, int>> done_segments;

    for (int i = 0; i < n; i++ ){
            cin >> lef;
            cin >> righ;
            m = 0;
            if (righ < lef){
                m = lef;
                lef = righ;
                righ = m;
            }
            segments.push_back(make_pair(lef, righ));
    }

    sort(segments.begin(), segments.end(), comp2);
    done_segments.push_back(segments[0]);

    for(int i = 0; i < n; i++){
        if(segments[i].first >= done_segments[done_segments.size()-1].second)
            done_segments.push_back(segments[i]);
    }
    sort(done_segments.begin(), done_segments.end(), comp1);
    cout << done_segments.size() << endl;

    for(int i = 0; i < done_segments.size(); i++){
        cout << done_segments[i].first<< ' ';
        cout << done_segments[i].second << '\n';
    }

    return 0;
}
