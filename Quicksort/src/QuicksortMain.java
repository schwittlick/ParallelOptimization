import java.io.PrintStream;
import java.util.Random;

public class QuicksortMain {
	/**
	 * @param args
	 * @throws
	 */
	public static void main(String[] args) {
		PrintStream printer = System.out;
		final int arrayLength = MyInput.getInt("Array length?", 10, 10000000);
		final int maxRandom = MyInput.getInt(
				"Maximum random number for the array ", 0, 10000000);
		final int CORES = Runtime.getRuntime().availableProcessors();
		printer.println("Number Cores: " + CORES);
		int[] array = getRandomArray(arrayLength, maxRandom);
		int[] array2 = copyArray(array);
		System.out.println("Starting to Sort.");
		sortSerial(array);
		sortThreaded(array2, CORES);
	}

	private static void sortSerial(int[] array) {
		System.out.println("");
		System.out.println("Starting to sort array serial");
		Quicksorter quicksorter = new Quicksorter(array);
		Timer timer = new Timer();
		quicksorter.quicksort();
		timer.stop();
		print(array);
		System.out.println("Ended to Sort Serial. Time needed: " + timer.getTime()
				+ "ms");
		
	}

	private static void sortThreaded(int[] array, int numberOfThreads) {
		System.out.println("");
		System.out.println("Starting to sort array threaded");
		Thread thread = new Thread(new QuicksorterRunnable(array2, numberOfThreads));
		Timer timer = new Timer();
		thread.start();
		waitForThreadIfPossible(thread);
		timer.stop();
		System.out.println("Ended to Sort Threaded. Time needed: " + timer.getTime()
				+ "ms");
		print(array);
	}

	private static void waitForThreadIfPossible(Thread thread) {
		try {
			thread.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static int[] copyArray(int[] array) {
		int[] result = new int[array.length];
		for (int i = array.length - 1; 0 <= i; --i) {
			result[i] = array[i];
		}
		return result;
	}

	/**
	 * 
	 * @param arrayLength
	 * @param maxRandom
	 * @return
	 */
	private static int[] getRandomArray(int arrayLength, int maxRandom) {
		int[] array = new int[arrayLength];
		Random random = new Random();
		for (int i = 0; i < array.length; i++) {
			array[i] = (int) random.nextInt(maxRandom);
		}
		return array;
	}

	/**
	 * 
	 * @param array
	 */
	private static void print(int[] array) {
		for (int i = 0; i < array.length; i++) {
			System.out.printf("%3d :", i);
		}
		System.out.println("");
		for (int i = 0; i < array.length; i++) {
			System.out.printf("%3d :", array[i]);
		}
		System.out.println("");
	}

	private int[] getLargeFixedArray() {
		int[] array = { 15, 51, 33, 41, 84, 36, 88, 96, 76, 8, 68, 95, 43, 59,
				92, 17, 84, 42, 90, 84, 74, 83, 65, 43, 33, 41, 84, 36, 88, 96,
				33, 41, 84, 36, 88, 96 };
		return array;
	}

	private int[] getSmallFixedArray() {
		int[] array = { 23, 12, 55, 94, 1, 12, 56, 22, 9, 76 };
		return array;
	}
}
