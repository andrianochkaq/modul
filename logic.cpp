#include "logic.h"

map<int, vector<int>> readTSV(const string& file) {
    ifstream in(file);
    if (!in.is_open())
        throw runtime_error("Cannot open file: " + file);

    map<int, vector<int>> data;
    string line;

    while (getline(in, line)) {
        stringstream ss(line);
        string student_id, subject, grade;

        if (!getline(ss, student_id, '\t') ||
            !getline(ss, subject, '\t') ||
            !getline(ss, grade))
            throw runtime_error("Invalid TSV format");

        int id = stoi(student_id);
        int grades = stoi(grade);

        data[id].push_back(grades);
    }

    return data;
}

void mergeData(map<int, vector<int>>& a, const map<int, vector<int>>& b) {
    for (const auto& [id, grades] : b) {
        a[id].insert(a[id].end(), grades.begin(), grades.end());
    }
}

map<int, double> calculateAverage(const map<int, vector<int>>& data) {
    map<int, double> result;

    for (const auto& [id, grades] : data) {
        if (grades.empty())
            throw runtime_error("Empty grades for student");

        double sum = 0;
        for (int g : grades)
            sum += g;

        result[id] = sum / grades.size();
    }

    return result;
}

void saveToJson(const map<int, double>& result, const string& file) {
    json j;

    for (const auto& [id, avg] : result) {
        j[to_string(id)] = avg;
    }

    ofstream out(file);
    if (!out.is_open())
        throw runtime_error("Cannot open output file");

    out << j.dump(4);
}