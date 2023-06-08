#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Student {
public:
    int isu;
    int points;

    Student(int isu, int points) : isu(isu), points(points) {}

    bool operator==(const Student& other) const {
        return isu == other.isu;
    }
    ~Student() {
        isu = 0;
        points = 0;
    }
};

class Test {
private:
    vector<list<Student>> groups;

public:
    Test(int M) : groups(M) {}

    void addStudent(int group, int isu, int points) {
        groups[group].push_back(Student(isu, points));
    }

    void removeStudent(int group, int isu) {
        Student s(isu, 0);
        groups[group].remove(s);
    }

    void calculateAverage(int group) const {
        int sum = 0;
        for (const auto& student : groups[group]) {
            sum += student.points;
        }
        int size = groups[group].size();
        if (size > 0) {
            cout << sum / size << '\n';
        }
    }

    void MaxPoints(int group) const {
        int maxPoints = 0;
        for (const auto& student : groups[group]) {
            maxPoints = max(maxPoints, student.points);
        }
        cout << maxPoints << '\n';
    }
    ~Test()= default;
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int M, Q;
    cin >> M >> Q;
    Test testing(M);

    char t;
    int group, isu, points;

    for (int i = 0; i < Q; ++i) {
        cin >> t >> group;
        group--;
        if (t == 'a') {
            testing.calculateAverage(group);
        } else if (t == '+') {
            cin >> isu >> points;
            testing.addStudent(group, isu, points);
        } else if (t == '-') {
            cin >> isu;
            testing.removeStudent(group, isu);
        } else if (t == 'm') {
            testing.MaxPoints(group);
        }
    }

    return 0;
}
