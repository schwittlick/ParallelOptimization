import java.util.Random;

/**
 * 
 * @author dennis
 *
 */
public class QuicksortThreaded extends Thread {
	int start;
	int end;
	private int[] array;

	/**
	 * 
	 * @param arrayLength
	 * @param maxRandom
	 */
	public QuicksortThreaded(int arrayLength, int maxRandom) {
		array = initArrayRandom(arrayLength, maxRandom);
	}
	
	/**
	 * 
	 * @param array
	 * @param start
	 * @param end
	 */
	public QuicksortThreaded(int[] array, int start, int end) {
		this.array = array;
		this.start = start;
		this.end = end;
		run();
	}
	
	public QuicksortThreaded(int[] array) {
		this.array = array;
		this.start = 0;
		this.end = array.length - 1;
	}

	public void run() {
		quicksort(this.start, this.end);
	}

	public int[] initArrayRandom(int arrayLength, int maxRandom) {
		int[] array = new int[arrayLength];
		Random random = new Random();
		for (int i = 0; i < array.length; i++) {
			array[i] = (int) random.nextInt(maxRandom);
		}
		return array;
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
		this.start = left;
		this.end = right;
		int pivotPlace = (start + end) / 2; //
		//pivotPlace += left;
		int pivotValue = array[pivotPlace];
		System.out.println("Pivot on: " + (pivotPlace + 1));
		System.out.println("Value is: " + pivotValue);
		//print(array);
		while (left < right) {
			while (array[left] < pivotValue) {
				left++;
			}
			while (array[right] > pivotValue) {
				right--;
			}
			if (left < right) {
				swap(left, right);
			}
			print(array);
		}
		if ((left - start) > 2) {
			QuicksortThreaded thread = new QuicksortThreaded(array, start, left);
			thread.start();
			//this.quicksort(start, left);
		}
		if ((end - right) > 2) {
			QuicksortThreaded thread2 = new QuicksortThreaded(array, start, left);
			thread2.start();
			//this.quicksort(right, end);
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
	 * @param array
	 */
	private void print(int[] array) {
		for (int i = 0; i < array.length; i++) {
			System.out.print(array[i] + ",");
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
