package domain.usecase.deleteEmail;

import domain.entity.User;

public interface DeleteEmail {
    public void deleteEmail(int id, User user) throws Exception;
}
