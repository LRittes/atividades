package domain.usecase.deleteEmail;

import domain.entity.User;
import domain.repository.DeleteEmailRep;

public class DeleteEmailImp implements DeleteEmail {
    private DeleteEmailRep _repository;

    public DeleteEmailImp(DeleteEmailRep repository) {
        _repository = repository;
    }

    @Override
    public void deleteEmail(int id, User user) throws Exception {
        _repository.deleteEmail(id, user);
    }

}
