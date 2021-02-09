#define MAX_COURSES 10001

struct Course {
	int time;
	int deadline;
};

class Solution {
public:
	int scheduleCourse(vector<vector<int>>& courses) {
		course_selected_size = 0;
		for (int i = 0; i < courses.size(); i++) {
			course_all[i].time = courses.at(i).at(0);
			course_all[i].deadline = courses.at(i).at(1);
		}
		quick_sort(course_all, 0, courses.size() - 1);

		int pastdays = 0;
		for (int i = 0; i < courses.size(); i++) {
			// 如果时间还够学当前课程，直接入堆
			if (pastdays + course_all[i].time <= course_all[i].deadline) {
				push_heap(course_all[i]);
				pastdays += course_all[i].time;
			}
			// 如果不够，替换掉目前所选的课程中最长的一门课(堆顶)
			else {
				if (course_selected_size == 0 || course_all[i].time >= course_selected[0].time) continue;
				pastdays += course_all[i].time;
				pastdays -= course_selected[0].time;
				course_selected[0] = course_all[i];
				reheap();
			}
		}
		return course_selected_size;
	}

private:
	Course course_all[MAX_COURSES];
	// 使用最大堆来保存已选课程
	Course course_selected[MAX_COURSES];
	int course_selected_size;

	void init() {
		course_selected_size = 0;
	}

	// 快速排序，根据课程deadline来排
	void quick_sort(Course array[], int left, int right) {
		if (left >= right) return;
		Course divide = array[left];
		int i = left, j = right;
		while (i < j) {
			while (i < j && divide.deadline < array[j].deadline) j--;
			if (i < j) array[i++] = array[j];
			while (i < j && array[i].deadline < divide.deadline) i++;
			if (i < j) array[j--] = array[i];
		}
		array[i] = divide;
		quick_sort(array, left, i - 1);
		quick_sort(array, i + 1, right);
	}

	void push_heap(Course course){
		course_selected[course_selected_size++] = course;
		int current = course_selected_size - 1;
		int parent = (current - 1) / 2;
		while (current > 0){
			if (course_selected[parent].time < course_selected[current].time){
				Course tmp = course_selected[parent];
				course_selected[parent] = course_selected[current];
				course_selected[current] = tmp;
				current = parent;
				parent = (current - 1) / 2;
			}
			else break;
		}
	}

	void reheap() {
		int current = 0;
		while (true) {
			int left = current * 2 + 1;
			int right = left + 1;
			int pos = current;
			if (left < course_selected_size && course_selected[pos].time < course_selected[left].time) pos = left;
			if (right < course_selected_size && course_selected[pos].time < course_selected[right].time) pos = right;
			if (pos != current){
				Course tmp = course_selected[pos];
				course_selected[pos] = course_selected[current];
				course_selected[current] = tmp;
				current = pos;
			}
			else break;
		}
	}
};