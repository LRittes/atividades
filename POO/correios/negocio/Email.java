package negocio;

public class Email {
    private int id;
    private String author;
    private String message;

    public int getId() {
        return id;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public Email(String author, String message) {
        this.author = author;
        this.message = message;
    }

}
