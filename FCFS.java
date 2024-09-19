import java.util.Scanner;

class Process{
	int process;
	int ct;
	int tt;
	int wt;
	int at;
	int bt;
	Scanner sc = new Scanner(System.in);
	void setInfo(){
		System.out.print("Enter Process Number:");
		process = sc.nextInt();
		System.out.print("Enter Arrival Time:");
		at = sc.nextInt();
		System.out.print("Enter Burst Time:");
		bt = sc.nextInt();
		
	}

	void getInfo(){
		System.out.println("P"+process+"\t\t"+at+"\t"+bt);
	}

	void sort(Process obj[],int totalProcess){
		Process temp = new Process();
		for(int i=0;i<totalProcess-1;i++){
			for(int j=i+1;j<totalProcess;j++){
				if(obj[i].at>obj[j].at){
					temp = obj[j];
					obj[j] = obj[i];
					obj[i] = temp;
				}
			}
		}
	}

	void getWholeProcess(Process p){
		System.out.println("P"+p.process+"\t"+p.at+"\t"+p.bt+"\t"+p.ct+"\t"+p.tt+"\t"+p.wt);
	}

	void fcfs(Process obj[],int totalProcess){
		obj[0].ct = obj[0].at + obj[0].bt;

		for(int i=1;i<totalProcess;i++){
			if(obj[i-1].ct >= obj[i].at)
				obj[i].ct = obj[i-1].ct + obj[i].bt;
			else
				obj[i].ct = obj[i].at + obj[i].bt;
		}
		float avgTT = 0,avgWT = 0;

		for(int i=0;i<totalProcess;i++){
			obj[i].tt = obj[i].ct - obj[i].at;
			obj[i].wt = obj[i].tt - obj[i].bt;
			avgTT += obj[i].tt;
			avgWT += obj[i].wt;
		}

		System.out.println("Process\tAT\tBT\tCT\tTT\tWT");
		for(int i=0;i<totalProcess;i++)
			getWholeProcess(obj[i]);

		System.out.println("Average Turn Around Time "+(avgTT/totalProcess)+"\nAverage Waiting Time :"+(avgWT/totalProcess));
	}

}

public class FCFS{
	public static void main(String []args){
		Scanner sc = new Scanner(System.in);

		System.out.print("\nEnter Total Processes:");
		int totalProcess = sc.nextInt();

		Process p[] = new Process[totalProcess];
		for(int i=0;i<totalProcess;i++)
			p[i] = new Process();

		System.out.println("\nEnter Process Number, Arrival Time and Burst Time");
		for(int i=0;i<totalProcess;i++)
			p[i].setInfo();
		System.out.println("Process \t AT \t BT");
		for(int i=0;i<totalProcess;i++)
			p[i].getInfo();
		
		p[0].sort(p, totalProcess);

		System.out.println("Process \t AT \t BT");
		for(int i=0;i<totalProcess;i++)
			p[i].getInfo();

		p[0].fcfs(p, totalProcess);	

		sc.close();
	}
}
