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
		Random random = new Random(maxRandom);
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
		int pivotPlace = (array.length / 2) - 1;
		int pivotValue = array[pivotPlace];
		int arrayBegin = 0;
		int arrayEnd = array.length - 1;
		int beginValue;
		int endValue;
		boolean change = true;
		boolean isSorted = false;
		while (change) {
			beginValue = array[arrayBegin];
			endValue = array[arrayEnd];
			if (beginValue < endValue) {
				arrayEnd--;
			} else {
				array[arrayBegin] = endValue;
				array[arrayEnd] = beginValue;
				arrayBegin++;
			}
			print(array);
		}
//TODO if smaller as pivot is ok
	}
}
