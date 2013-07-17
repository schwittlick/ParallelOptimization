/**
 * 
 * @author Dennis Haegler
 *
 */
public class Quicksort {
	/** The array to sort.*/
	protected int[] array;
	
	/**Starting location to start from.*/ 
	protected int start;
	
	/** Ending location to end with.*/
	protected int end;
	
	/** The logger from loger4j to log information in the class*/
	//private static //logger //logger = //logger.get//logger(Quicksort.class);
	
	/**
	 * 
	 * @param array
	 */
	public Quicksort(int[] array) {
		init(array, 0, array.length - 1);
	}
	
	/**
	 * 
	 * @param array
	 * @param start
	 * @param end
	 */
	public Quicksort(int[] array, int start, int end) {
		init(array, start, end);
	}

	/**
	 * Runs the quicksort.
	 */
	public void run() {
		quicksort(start, end);
	}

	/**
	 * Sorts the elements of the values in the array from the left to the right
	 * index.
	 * 
	 * @param array
	 *            The Array to sort.
	 * @param left
	 *            the start of the sort algorithm.
	 * @param right
	 *            the end of the index in the array for the sort algorithm
	 */
	public void quicksort(int left, int right) {
		//logger.info("Starts quickst from " + left + " to " + right);
		int start = left;
		int end = right;
		int pivotPlace = (start + (end + 1)) / 2;
		int pivotValue = array[pivotPlace];
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
				//TODO check on same values and diable -- or ++
				//logger.debug("Swapped " + array[left] + " and " + array[right]);
				swap(left, right);
			} 
			if (left == right) {
				//logger.debug("Swapped Pivot" + array[left] 
			//			+ " and " + array[pivotPlace]);
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
			this.quicksort(start, left);
		}
		if ((end - right) >= 1) {
			//logger.debug("RIGHTSORT");
			this.quicksort(right, end);
		}
		//logger.debug(this.toString());
	}

	/**
	 * Returns the array from the quicksort as a String.
	 * 
	 * @return the array as String.
	 */
	public String toString() {
		String string = "";
		for (int i = 0; i < array.length; i++) {
			string += array[i] + ":";
		}
		return string;
	}
	
	/**
	 * 
	 * @return
	 */
	public boolean isSorted() {
		boolean isSorted = false;
		for (int i = 0; i < array.length - 1; i++) {
			if(array[i] > array[i + 1]) {
				return isSorted;
			}
		}
		isSorted = true;
		return isSorted;
	}

	/**
	 * Swaps two values in the array. The value from indexLeft will be swapped
	 * with the value from indexRight.
	 * 
	 * @param array
	 *            a array of integer where the values get swapped.
	 * @param indexLeft
	 *            the index of one of the values to swap.
	 * @param indexRight
	 *            the index of one of the values to swap.
	 */
	protected void swap(int indexLeft, int indexRight) {
		int buffer = array[indexLeft];
		array[indexLeft] = array[indexRight];
		array[indexRight] = buffer;
	}
	
	/**
	 * Initializes a Quicksort.
	 * 
	 * @param array
	 * @param start
	 * @param end
	 */
	private void init(int[] array, int start, int end) {
		this.array = array;
		this.start = start;
		this.end = end;
	}
}
