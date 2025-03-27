package com.sanyam.eshop_backend.eshop_rest_api.service;

import com.sanyam.eshop_backend.eshop_rest_api.entity.Category;
import java.util.List;

public interface CategoryService {
    List<Category> getAllCategories();
    Category getCategoryById(Long categoryId);
    Category createCategory(Category category);
    Category updateCategory(Long categoryId, Category updatedCategory);
    void deleteCategory(Long categoryId);
}
