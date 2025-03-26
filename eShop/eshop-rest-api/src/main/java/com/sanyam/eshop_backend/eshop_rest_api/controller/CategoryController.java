package com.sanyam.eshop_backend.eshop_rest_api.controller;

import com.sanyam.eshop_backend.eshop_rest_api.entity.Category;
import com.sanyam.eshop_backend.eshop_rest_api.service.CategoryService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@CrossOrigin(origins = "*", maxAge = 3600)
@RestController
@RequestMapping("/api/categories")
public class CategoryController {
    @Autowired
    private CategoryService categoryService;

    @GetMapping
    public ResponseEntity<List<Category>> getAllCategories(){
        var data = categoryService.getAllCategories();
        return ResponseEntity.ok(data);
    }

    @GetMapping("/{categoryId}")
    public ResponseEntity<Category> getCategoryById(@PathVariable("categoryId") Long categoryId){
        var data = categoryService.getCategoryById(categoryId);
        return ResponseEntity.ok(data);
    }

    @PostMapping
    public ResponseEntity<Category> createCategory(@RequestBody Category category){
        var data = categoryService.createCategory(category);
        return ResponseEntity.ok(data);
    }

    @PutMapping("/{categoryId}")
    public ResponseEntity<Category> updateCategory(@PathVariable("categoryId") Long categoryId,
                                                   @RequestBody Category category){
        var data = categoryService.updateCategory(categoryId, category);
        return ResponseEntity.ok(data);
    }

    @DeleteMapping("/{categoryId}")
    public ResponseEntity<Void> deleteCategory(@PathVariable("categoryId") Long categoryId){
        categoryService.deleteCategory(categoryId);
        return ResponseEntity.noContent().build();
    }
}
