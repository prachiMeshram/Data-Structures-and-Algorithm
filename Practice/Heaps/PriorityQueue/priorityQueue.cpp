#include<bits/stdc++.h>


using namespace std;


const long long int N = 1e6+2;
const long long int MOD = 1e9+7;


#define F	first
#define S	second
#define pb	push_back
#define POB	pop_back
#define MP	make_pair
#define ump	unordered_map
#define int	long long int
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pi;

class Student {
    public:
    string name;
    int rank;

    Student(string n, int r): name(n), rank(r) {};
};

bool myComparision (Student &s1, Student &s2) {
    if (s1.rank == s2.rank) {
        return s1.name > s2.name;
    }

    return s1.rank > s2.rank;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<Student, vector<Student>, decltype(&myComparision)> pq(&myComparision);

    pq.push(Student("A", 3));
    pq.push(Student("C", 2));
    pq.push(Student("B", 2));

    while (!pq.empty()) {
        Student s = pq.top();
        cout << s.name << "-> " << s.rank << endl;
        pq.pop();
    }

    return 0;
}