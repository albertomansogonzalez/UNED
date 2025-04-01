package es.uned.lsi.eped.pract2024_2025;

public class Task implements TaskIF {

	/* Declaración de atributos para almacenar la información de una tarea */
	private boolean isCompleted;
	private String text;
	private int date;

	/* Constructores*/
	public Task() {

	}
	public Task(boolean isCompleted, String text, int date) {
		this.isCompleted = isCompleted;
		this.text = text;
		this.date = date;
	}
	
	/* Marca la tarea como completada */
	@Override
	public void setCompleted() {
		isCompleted = true;
	}
	
	/* Devuelve el texto de la tarea */
	@Override
	public String getText() {
		return text;
	}

	/* Devuelve la fecha de la tarea */
	@Override
	public int getDate() {
		return date;
	}

	/* Devuelve si la tarea ha sido completada o no */
	@Override
	public boolean getCompletion() {
		return isCompleted;
	}

	/* Compara la tarea actual con una tarea llamante */
	@Override
	public int compareTo(TaskIF T) {
		if (date > T.getDate()) {
			return 1;
		}else if (date < T.getDate()){
			return -1;
		}else {
			return 0;
		}
	}

}
