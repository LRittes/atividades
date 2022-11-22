package domain.entity;

import java.util.List;

public class Email {
    private int id;
    private String author;
    private String receiver;
    private String message;
    private List<Integer> emailsAnswered;

    public List<Integer> getEmailsAnswered() {
        return emailsAnswered;
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

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getReceiver() {
        return receiver;
    }

    public void setReceiver(String receiver) {
        this.receiver = receiver;
    }

    public Email(String author, String message) {
        this.author = author;
        this.message = message;
    }

    public Email(int id, String author, String receiver, String message) {
        this.id = id;
        this.author = author;
        this.receiver = receiver;
        this.message = message;
    }

}
