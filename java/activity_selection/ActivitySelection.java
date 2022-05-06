/*
One is given n activities with their start and finish times. Select the maximum number of activities
that can be performed, assuming that a person can only work on a single activity at a time.

activity      a1      a2      a3      a4      a5      a6
start:        0       3       1       5       5       8
finish:       6       4       2       8       7       9



**** activity selection ****


 */


package activity_selection;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class ActivitySelection {
  // sort activities with their start and end times
  static void activitySelection(ArrayList<Activity> activityList) {
    Comparator<Activity> finishTimeComparator = new Comparator<Activity>() {
      @Override
      public int compare(Activity o1,Activity o2) {
        return o1.getFinishTime() - o2.getFinishTime();
      }
    };

    Collections.sort(activityList,finishTimeComparator);
    Activity previousActivity = activityList.get(0);

    System.out.println("activity schedule:\n" + activityList.get(0));

    for (int i = 1; i < activityList.size(); i++) {
      Activity activity = activityList.get(i);
      if (activity.getStartTime() >= previousActivity.getFinishTime()) {
        System.out.println(activity);
        previousActivity = activity;
      }
    }
  }

  public static void main(String[] args) {
    System.out.println("**** activity selection ****");
    ArrayList<Activity> activityList = new ArrayList<Activity>();
    activityList.add(new Activity("A1",0,6));
    activityList.add(new Activity("A2",3,4));
    activityList.add(new Activity("A3",1,2));
    activityList.add(new Activity("A4",5,8));
    activityList.add(new Activity("A5",5,7));
    activityList.add(new Activity("A6",8,9));

    ActivitySelection.activitySelection(activityList);
  }
}
