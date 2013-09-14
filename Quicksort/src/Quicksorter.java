/**
 * 
 * @author Dennis Haegler
 * 
 */
public class Quicksorter {
<<<<<<< HEAD
	/** The array to sort.*/
=======
	/** The array to sort. */
>>>>>>> ae5af0b6f49908364afac6080ed1b9d84252b82f
	protected int[] array;

	/** Starting location to start from. */
	protected int start;

	/** Ending location to end with. */
	protected int end;

	/**
	 * 
	 * @param array
	 */
	public Quicksorter(int[] array) {
		init(array, 0, array.length - 1);
	}

	/**
	 * 
	 * @param array
	 * @param start
	 * @param end
	 */
	public Quicksorter(int[] array, int start, int end) {
		init(array, start, end);
	}

	/**
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
	
	/**
	 * Runs the quicksort.
	 */
	public void quicksort() {
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
		int start = left;
		int end = right;
		int pivotPlace = (start + (end + 1)) / 2;
		int pivotValue = array[pivotPlace];
		while (left < right) {
			while (array[left] <= pivotValue && left < end) {
				left++;
			}
			while (array[right] >= pivotValue && start < right) {
				right--;
			}
			if (left < right) {
				swap(left, right);
			}
			if (left == right) {
				swap(left, pivotPlace);
			}
		}
		left--;
		right++;
		if ((left - start) >= 1) {
			this.quicksort(start, left);
		}
		if ((end - right) >= 1) {
			this.quicksort(right, end);
		}
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
			if (array[i] > array[i + 1]) {
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
	private void swap(int indexLeft, int indexRight) {
		int buffer = array[indexLeft];
		array[indexLeft] = array[indexRight];
		array[indexRight] = buffer;
	}
}
