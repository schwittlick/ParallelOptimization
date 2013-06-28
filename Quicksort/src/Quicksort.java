import java.util.Random;
import org.apache.log4j.Logger;

/**
 * 
 * @author Dennis Haegler
 *
 */
public class Quicksort {
	/** The array to sort.*/
	private int[] array;
	
	/**Starting location to start from.*/ 
	private int start;
	
	/** Ending location to end with.*/
	private int end;
	
	/** The logger from loger4j to log information in the class*/
	private static Logger logger = Logger.getLogger(Quicksort.class);
	
	/**
	 * 
	 * @param array
	 */
	public Quicksort(int[] array) {
		this.array = array;
		this.start = 0;
		this.end = array.length -1;
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
		logger.info("Starts quickst from " + left + " to " + right);
		int start = left;
		int end = right;
		int pivotPlace = (start + end) / 2;
		int pivotValue = array[pivotPlace];
		logger.debug("start->" + array[left] + " end->" + array[right] 
				+ " Pivot on: " + pivotPlace + " Value is: " + pivotValue);
		logger.debug(toString());
		while (left < right) {
			while (array[left] < pivotValue) {
				logger.debug("check Left:" + array[left] 
						+ " is lower than pivot " + pivotValue);
				left++;
			}
			logger.debug("DETECT " + array[left] + " on " + left 
					+ " is bigger than " + pivotValue);
			while (array[right] > pivotValue) {
				logger.debug("check Right:" + array[right] 
						+ " is bigger than pivot " + pivotValue);
				right--;
			}
			logger.info("DETECT " + array[right] + " on " + right 
					+ " is smaller than " + pivotValue);
			if (left < right) {
				logger.debug("Swapped " + array[left] + " and " + array[right]);
				swap(left, right);
				left++;
				right--;
			}
			if(left == right) {
				logger.debug("Swapped Pivot" + array[left] 
						+ " and " + array[pivotPlace]);
				swap(left, pivotPlace);
			}
		}
		logger.debug("Ends sorting step. left->" + left + " right->" + right);
		logger.debug("Ends sorting step. start->" + start + " end->" + end);
		logger.debug(toString());
		left--;
		right++;
		if ((left - start) >= 2) {
			logger.debug("LEFTSORT");
			this.quicksort(start, left);
		}
		if ((end - right) >= 2) {
			logger.debug("RIGHTSORT");
			this.quicksort(right, end);
		}
		logger.debug(this.toString());
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
	 * @param array
	 */
	private void print(int[] array) {
		for (int i = 0; i < array.length; i++) {
			System.out.printf("%3d :", i);
		}
		System.out.println("");
		for (int i = 0; i < array.length; i++) {
			System.out.printf("%3d :", array[i]);
		}
		System.out.println("");
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
	private void swap(int indexLeft, int indexRight) {
		int buffer = array[indexLeft];
		array[indexLeft] = array[indexRight];
		array[indexRight] = buffer;
	}
}
