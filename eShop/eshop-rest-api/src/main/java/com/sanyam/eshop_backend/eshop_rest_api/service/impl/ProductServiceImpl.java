package com.sanyam.eshop_backend.eshop_rest_api.service.impl;

import com.sanyam.eshop_backend.eshop_rest_api.entity.Category;
import com.sanyam.eshop_backend.eshop_rest_api.entity.Product;
import com.sanyam.eshop_backend.eshop_rest_api.repository.CategoryRepository;
import com.sanyam.eshop_backend.eshop_rest_api.repository.ProductRepository;
import com.sanyam.eshop_backend.eshop_rest_api.service.ProductService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class ProductServiceImpl implements ProductService {
    @Autowired
    private CategoryRepository categoryRepository;
    @Autowired
    private ProductRepository productRepository;

    private Product getProduct(Long productId){
        return productRepository.findById(productId)
                .orElseThrow(() -> new RuntimeException("Product not found with id: " + productId));
    }
    private Category getCategory(Long categoryId){
        return categoryRepository.findById(categoryId)
                .orElseThrow(() -> new RuntimeException("Category not found with id: " + categoryId));
    }

    private boolean validateCategoryAndProductId(Long categoryId, Long productId){
        Product product = getProduct(productId);
        return (!product.getCategory().getId().equals(categoryId));
    }

    @Override
    public List<Product> getAllProducts(Long categoryId) {
        Category category = getCategory(categoryId);
        return productRepository.findByCategoryId(categoryId);
    }

    @Override
    public Product getProductById(Long categoryId, Long productId) {
        if(validateCategoryAndProductId(categoryId, productId)){
            throw new RuntimeException("Product and Category don't match.");
        }
        return getProduct(productId);
    }

    @Override
    public Product createProduct(Long categoryId, Product newProduct) {
        Category category = getCategory(categoryId);
        newProduct.setCategory(category);
        return productRepository.save(newProduct);
    }

    @Override
    public Product updateProduct(Long categoryId, Long productId, Product updatedProduct) {
        if(validateCategoryAndProductId(categoryId, productId)){
            throw new RuntimeException("Product and Category do not match.");
        }
        Product product = getProduct(productId);
        product.setName(updatedProduct.getName());
        product.setDescription(updatedProduct.getDescription());
        product.setPrice(updatedProduct.getPrice());
        product.setCategory(getCategory(categoryId));
        return productRepository.save(product);
    }

    @Override
    public void deleteProduct(Long categoryId, Long productId) {
        if(validateCategoryAndProductId(categoryId, productId)){
            throw new RuntimeException("Category and Product do not match.");
        }
        Product product = getProduct(productId);
        productRepository.delete(product);
    }
}
