package com.sanyam.eshop_backend.eshop_rest_api.repository;

import com.sanyam.eshop_backend.eshop_rest_api.entity.User;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.Optional;

public interface UserRepository extends JpaRepository<User, Long> {
    Optional<User> findByEmail(String email);
    Optional<User> findByUsername(String username);
    Boolean existsByEmail(String email);
    Boolean existsByUsername(String username);
    Optional<User> findByEmailOrUsername(String usernameOrEmail, String usernameOrEmail1);
}
