package ui.button;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JPanel;

public class ButtonPanel extends JPanel implements ActionListener {
	private MyButton invertButton;
	private MyButton gausButton;
	private MyButton brighterButton;
	private MyButton darkerButton;

	public ButtonPanel() {
		invertButton = new MyButton("Invert");
		gausButton = new MyButton("Gaus");
		brighterButton = new MyButton("+");
		darkerButton = new MyButton("-");
		setUp();
	}

	private void setUp() {
		this.add(invertButton);
		this.add(gausButton);
		this.add(brighterButton);
		this.add(darkerButton);
		this.setVisible(true);
	}

	private void addAllButtonsAnActionListener() {
		invertButton.addActionListener(this);
		gausButton.addActionListener(this);
		brighterButton.addActionListener(this);
		darkerButton.addActionListener(this);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource().equals(invertButton)) {

		} else if (e.getSource().equals(gausButton)) {

		} else if (e.getSource().equals(brighterButton)) {

		} else if (e.getSource().equals(darkerButton)) {

		}

	}
}
