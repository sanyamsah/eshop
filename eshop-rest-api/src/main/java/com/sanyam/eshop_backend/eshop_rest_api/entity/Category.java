package com.sanyam.eshop_backend.eshop_rest_api.entity;

import com.fasterxml.jackson.annotation.JsonIgnore;
import jakarta.persistence.*;
import jakarta.validation.constraints.NotEmpty;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;
import java.util.List;

@Entity
@NoArgsConstructor
@AllArgsConstructor
@Table(
        name = "categories",
        uniqueConstraints = {
                @UniqueConstraint(columnNames = {"name"})
        }
)
public class Category {
    @Id
    @GeneratedValue(
            strategy = GenerationType.IDENTITY
    )
    private Long id;
    @Column(name = "name", nullable = false, unique = true)
    @NotEmpty(message = "Category name is required")
    private String name;
    @Column(name = "description")
    private String description;
    @Column(name = "image", nullable = false)
    private String image;
    @OneToMany(
            mappedBy = "category", // one product is mapped by the category field in Product entity
            cascade = CascadeType.ALL, // category saved/deleted => products saved/deleted
            orphanRemoval = true // if a Product is deleted from the products set, it is deleted from the database
    ) // one category can have many products
//    @JsonIgnore
    @Column(name = "products")
    private List<Product> products;

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getImage() {
        return image;
    }

    public void setImage(String image) {
        this.image = image;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public List<Product> getProducts() {
        return products;
    }

    public void setProducts(List<Product> products) {
        this.products = products;
    }
}
