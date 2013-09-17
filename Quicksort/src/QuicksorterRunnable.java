import java.util.ArrayList;
import java.util.List;

public class QuicksorterRunnable implements Runnable {
	int[] array;
	int start;
	int end;
	int numberCores;

	public QuicksorterRunnable(int[] array, int numberCores) {
		init(array, 0, array.length, numberCores);
		this.numberCores = numberCores;
	}

	public QuicksorterRunnable(int[] array, int start, int end, int numberCores) {
		init(array, start, end, numberCores);
	}

	private void init(int[] array, int start, int end, final int numberCores) {
		this.array = array;
		this.start = start;
		this.end = end;
		this.numberCores = numberCores;
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


	public void run() {
		quicksort(start, end, numberCores);
	}

	public void quicksort(int left, int right, int numberCores) {
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
			// TODO start a new Runnable job
		}
		if ((end - right) >= 1) {
			// TODO start a new Thread
		}

		if (numberCores > 0) {
			final List<Thread> threads = new ArrayList<Thread>();
			if (left - start > 1) {
				final Runnable runnable = new QuicksorterRunnable(array,
						start, left - 1, numberCores - 1);
				threads.add(new Thread(runnable));
			}
			if (end - right > 1) {
				final Runnable runnable = new QuicksorterRunnable(array,
						start, left - 1, numberCores - 1);
				threads.add(new Thread(runnable));
			}
			for (final Thread thread : threads)
				thread.start();
			try {
				for (final Thread thread : threads)
					thread.join();
			} catch (final InterruptedException e) {
				e.printStackTrace();
			}
		} else {
			if (left - start > 1)
				quicksort(start, left - 1, numberCores);
			if (end - right > 1)
				quicksort(left + 1, end, numberCores);
		}
	}

	private void swap(int indexLeft, int indexRight) {
		int buffer = array[indexLeft];
		array[indexLeft] = array[indexRight];
		array[indexRight] = buffer;
	}
}