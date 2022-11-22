package domain.repository;

import domain.entity.User;

public interface DeleteEmailRep {
    public void deleteEmail(int idEmail, User user) throws Exception;
}
