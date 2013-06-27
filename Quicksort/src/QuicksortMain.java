import java.util.Random;

public class QuicksortMain {
	private int[] array;

	public QuicksortMain(int arrayLength, int maxRandom) {
		array = initArrayRandom(arrayLength, maxRandom);
	}
	
	public QuicksortMain(int[] array) {
		this.array = array;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		/*final int arrayLength = MyInput.getInt("Array length? 10 - 100 ", 10,
				100);
		final int maxRandom = MyInput.getInt(
				"Maximum random number for the array ", 0, 10000000);*/
		int[] array = {22, 42, 11, 2, 34, 3, 20, 28, 27, 44};
		QuicksortMain app = new QuicksortMain(array);
		app.run();
	}

	public void run() {
		System.out.println("Array length = " + array.length);
		quicksort(0, array.length - 1);
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
		int start = left;
		int end = right;
		int pivotPlace = (start + end) / 2; //
		//pivotPlace += left;
		int pivotValue = array[pivotPlace];
		System.out.println("Pivot on: " + (pivotPlace + 1));
		System.out.println("Value is: " + pivotValue);
		print(array);
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
			this.quicksort(start, left);
		}
		if ((end - right) > 2) {
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
	 * @param array
	 */
	private void print(int[] array) {
		for (int i = 0; i < array.length; i++) {
			System.out.print(array[i] + ":");
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
