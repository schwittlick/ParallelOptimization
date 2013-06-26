import java.util.Random;

public class QuicksortMain {
	private int[] array;

	public QuicksortMain(int arrayLength, int maxRandom) {
		array = initArrayRandom(arrayLength, maxRandom);
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		final int arrayLength = MyInput.getInt("Array length? 10 - 100 ", 10,
				100);
		final int maxRandom = MyInput.getInt(
				"Maximum random number for the array ", 0, 10000000);
		QuicksortMain app = new QuicksortMain(arrayLength, maxRandom);
		app.run();
	}

	public void run() {
		System.out.println("Array length = " + array.length);
		print(array);
		quicksort(array);
	}

	public int[] initArrayRandom(int arrayLength, int maxRandom) {
		int[] array = new int[arrayLength];
		Random random = new Random();
		for (int i = 0; i < array.length; i++) {
			array[i] = (int) random.nextInt(maxRandom);
		}
		return array;
	}

	public void print(int[] array) {
		for (int i = 0; i < array.length; i++) {
			System.out.print(array[i] + ":");
		}
		System.out.println("");
	}

	public void quicksort(int[] array) {
		quicksort(array, 0, (array.length - 1));
	}

	/**
	 * While left is smaller than pivot -> left++. While right is bigger ->
	 * right--.
	 * 
	 * @param array
	 * @param left
	 * @param right
	 */
	public void quicksort(int[] array, int left, int right) {
		int start = left;
		int pivotPlace = (right - left) / 2;
		int pivotValue = array[pivotPlace];
		boolean change = false;
		System.out.println("Pivot on: " + (pivotPlace + 1));
		System.out.println("Value is: " + pivotValue);
		while (right != left) {
			while (array[left] < pivotValue) {
				left++;
			}
			while (array[right] > pivotValue) {
				right--;
			}
			if (right != left) {
				swap(array, left, right);
			}
			print(array);
		}
	}

	private void swap(int[] array, int indexLeft, int indexRight) {
		int buffer = array[indexLeft];
		array[indexLeft] = array[indexRight];
		array[indexRight] = buffer;
	}
}
