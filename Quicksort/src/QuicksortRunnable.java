//import org.apache.log4j.logger;

public class QuicksortRunnable extends Quicksort implements Runnable {
	/** */
	//private static Logger logger = logger.getlogger(QuicksortRunnable.class);
	
	/**
	 * 
	 * @param array
	 */
	public QuicksortRunnable(int[] array) {
		super(array);
	}
	
	/**
	 * 
	 * @param array
	 * @param start
	 * @param end
	 */
	public QuicksortRunnable(int[] array, int start, int end) {
		super(array,start, end);
	}
	
	/**
	 * 
	 */
	@Override
	public void run() {
		quicksort(start, end);
	}
	
	/**
	 * 
	 */
	@Override
	public void quicksort(int left, int right) {
		//logger.info("Starts quickst from " + left + " to " + right);
		int start = left;
		int end = right;
		int pivotPlace = (start + (end + 1)) / 2;
		int pivotValue = array[pivotPlace];
		//logger.debug("start->" + array[left] + " end->" + array[right] 
		//		+ " Pivot on: " + pivotPlace + " Value is: " + pivotValue);
		//logger.debug(toString());
		while (left < right) {
			while (array[left] <= pivotValue && left < end) {
				left++;
			}
			//logger.debug("DETECT left " + array[left] + " on " + left + " is bigger than " + pivotValue);
			while (array[right] >= pivotValue && start < right) {
				right--;
			}
			//logger.info("DETECT right " + array[right] + " on " + right + " is smaller than " + pivotValue);
			if (left < right) {
				//logger.debug("Swapped " + array[left] + " and " + array[right]);
				swap(left, right);
			} 
			if (left == right) {
				//logger.debug("Swapped Pivot" + array[left] 
				//		+ " and " + array[pivotPlace]);
				swap(left, pivotPlace);
			}
		}
		//logger.debug("Ends sorting step. left->" + left + " right->" + right);
		//logger.debug("Ends sorting step. start->" + start + " end->" + end);
		//logger.debug(toString());
		left--;
		right++;
		if ((left - start) >= 1) {
			//logger.debug("LEFTSORT");
			new Thread(new QuicksortRunnable(this.array, start, left)).start();
			//this.quicksort(start, left);
		}
		if ((end - right) >= 1) {
			//logger.debug("RIGHTSORT");
			new Thread(new QuicksortRunnable(this.array, right, end)).start();
			//this.quicksort(right, end);
		}
		//logger.debug(this.toString());
	}
 }