#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <tuple>
using namespace std;


enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

using TasksInfo = map<TaskStatus, int>;


class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const
  {
    return (m.at(person));
  }
  
  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person)
  {
      m[person][TaskStatus::NEW]++;
  }
  
  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count)
      {
        TasksInfo starii;
        TasksInfo old = m[person];
        TasksInfo novii;
        int nw;
        int counter;
        if ((nw = old[TaskStatus::NEW]) > 0)
        {
          while (nw > 0 && task_count > 0)
          {
            m[person][TaskStatus::NEW]--;
            counter = m[person][TaskStatus::NEW];
            m[person][TaskStatus::IN_PROGRESS]++;
            novii[TaskStatus::IN_PROGRESS]++;
            task_count--;
            nw--;
          }
          if (counter)
            starii[TaskStatus::NEW] = counter;
        }
        counter = 0;
        if ((nw = old[TaskStatus::IN_PROGRESS]) > 0)
        {
          while (nw > 0 && task_count > 0)
          {
            m[person][TaskStatus::IN_PROGRESS]--;
            counter = m[person][TaskStatus::IN_PROGRESS];
            m[person][TaskStatus::TESTING]++;
            novii[TaskStatus::TESTING]++;
            nw--;
            task_count--;
          }
          if (counter)
            starii[TaskStatus::IN_PROGRESS] = counter;
        }
        counter = 0;
        if ((nw = old[TaskStatus::TESTING]) > 0)
        {
          while (nw > 0 && task_count > 0)
          {
            m[person][TaskStatus::TESTING]--;
            counter = m[person][TaskStatus::TESTING];
            m[person][TaskStatus::DONE]++;
            novii[TaskStatus::DONE]++;
            nw--;
            task_count--;
          }
          if (counter)
            starii[TaskStatus::TESTING] = counter;
          counter = 0;
        }
        if (m[person][TaskStatus::NEW] && m[person][TaskStatus::NEW] !=  novii[TaskStatus::NEW])
          starii[TaskStatus::NEW] = m[person][TaskStatus::NEW];
        if (m[person][TaskStatus::IN_PROGRESS] && m[person][TaskStatus::IN_PROGRESS] !=  novii[TaskStatus::IN_PROGRESS])
          starii[TaskStatus::IN_PROGRESS] = m[person][TaskStatus::IN_PROGRESS];
        if (m[person][TaskStatus::TESTING] && m[person][TaskStatus::TESTING] !=  novii[TaskStatus::TESTING])
          starii[TaskStatus::TESTING] = m[person][TaskStatus::TESTING];
        return tie(novii, starii);
      }
    private:
        map<string, TasksInfo> m;
};

void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " NEW" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " IN_PROGRESS" <<
      ", " << tasks_info[TaskStatus::TESTING] << " TEST" <<
      ", " << tasks_info[TaskStatus::DONE] << " DONE" << endl;
}


int main() {
  TeamTasks tasks;
  for (int i = 0; i < 5; ++i) {
    tasks.AddNewTask("Alice");
  }
  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

  TasksInfo updated_tasks, untouched_tasks;
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Alice", 5);
  PrintTasksInfo(updated_tasks);
  PrintTasksInfo(untouched_tasks);
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Alice", 5);
  PrintTasksInfo(updated_tasks);
  PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Alice", 1);
  PrintTasksInfo(updated_tasks);
  PrintTasksInfo(untouched_tasks);

    for (int i = 0; i < 5; ++i) {
    tasks.AddNewTask("Alice");
  }
  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

      tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Alice", 2);
  PrintTasksInfo(updated_tasks);
  PrintTasksInfo(untouched_tasks);

      tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Alice", 4);
  PrintTasksInfo(updated_tasks);
  PrintTasksInfo(untouched_tasks);
  return 0;
}